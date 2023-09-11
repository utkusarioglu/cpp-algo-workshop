from conan import ConanFile
from conan.tools.cmake import CMake, CMakeToolchain, CMakeDeps, cmake_layout
from os import getcwd, makedirs, chmod, path
from stat import S_IRWXG, S_IRWXU, S_IROTH, S_IXOTH 
from shutil import copy2

class Emscripten(ConanFile):  
    name = "cpp-algo-workshop"
    version = "1.0.0"
    package_type = "application"
    build_policy = "missing"
    settings = "os", "arch", "compiler", "build_type"

    exports = "CMakeLists.txt",

    # def configure(self):
    #     self.options["spdlog"].shared = True

    def layout(self):
        build_relpath = self._get_build_path()
        self.folders.source = "."
        self.folders.build = build_relpath
        self.folders.generators = f"{build_relpath}/generators"
        self.cpp.source.includeDirs = ["include"]
        self.cpp.build.libdirs = "."
        self.cpp.build.bindirs = "."


    def requirements(self):
        self.requires("spdlog/1.12.0")
        # This should only be included if we are running some test
        self.requires("gtest/1.14.0")
    
    # def imports(self):
    #     self.copy("*.html", dst="bin", src="bin")
    #     self.copy("*.js", dst="bin", src="bin")
    #     self.copy("*.wasm", dst="bin", src="bin")
    
    # def test(self):
    #     print("Do this later, it requires knowing how to package code")

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate()
        deps = CMakeDeps(self)
        deps.generate()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = [self.name]

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
        self._after_build()

    def _after_build(self):
        release_dir = getcwd()
        base_folder = self.folders._base_source
        os = self.settings.os

        match os:
            case "Emscripten":
                print("Creating bin for Emscripten…")
                makedirs("bin", exist_ok=True)
                public_dir = f"{base_folder}/public"
                copy2(f"{release_dir}/{self.name}.js", f"{release_dir}/bin/wasm.js")
                copy2(f"{public_dir}/index.html", f"{release_dir}/bin/index.html")

            case "Linux":
                print("Creating bin for Linux…")
                makedirs("bin", exist_ok=True)
                for target in ["src", "test"]:
                    target_relpath = f"{release_dir}/{target}"
                    bin_relpath = f"{release_dir}/bin"
                    if not path.exists(target_relpath):
                        print(f"Warning: Target path '{target}' doesn't exist")
                        continue
                    source_filename = f"{self.name}-{target}"
                    source_relpath = f"{target_relpath}/{source_filename}"
                    target_relpath = f"{bin_relpath}/{source_filename}"
                    copy2(source_relpath, target_relpath)
                    chmod(target_relpath, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH)
            case _:
                raise ValueError(f"Unknown os {self.settings.os}")
    
    def _get_build_path(self) -> str:
        build_type = str(self.settings.build_type).lower()
        arch_lower = str(self.settings.arch).lower()
        os_lower = str(self.settings.os).lower()

        match os_lower:
            case "emscripten":
                return f"build/{arch_lower}/{build_type}"
            case "linux":
                return f"build/{os_lower}/{build_type}"
            case _:
                raise ValueError(f"Unknown os {self.settings.os}")
