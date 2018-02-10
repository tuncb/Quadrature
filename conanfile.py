from conans import ConanFile

class BlitzConan(ConanFile):
    name = "quadrature"
    version = "0.1.0"
    license = "https://www.apache.org/licenses/LICENSE-2.0"
    url = "https://github.com/tuncb/Quadrature"
    description = ("A small library for implementation of quadrature rules.")
    settings = "os", "compiler", "build_type", "arch"

    def package_id(self):
        self.info.header_only()

    def package(self):
        self.copy("*", dst="quadrature", src="./include/quadrature")

    def package_info(self):
        self.cpp_info.includedirs = ['.']
