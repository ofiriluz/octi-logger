from conans import ConanFile, CMake


class OctiLoggerConanFile(ConanFile):
    name = "octi-logger"
    version = open('VERSION', 'r').read()
    settings = "os", "compiler", "arch", "build_type"

    def requirements(self):
        pass

    def imports(self):
        pass

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        # cmake.build(target="clean")
        cmake.build()
        cmake.install()
    
    def package(self):
        pass