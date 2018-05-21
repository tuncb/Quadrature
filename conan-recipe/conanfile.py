from conans import ConanFile

class QuadratureConan(ConanFile):
    name = "quadrature"
    version = "1.0.0"
    license = "https://www.apache.org/licenses/LICENSE-2.0"
    url = "https://github.com/tuncb/Quadrature"
    description = ("A library for implementation of quadrature rules.")

    def package(self):
        self.copy("*", dst="quadrature", src="../projects/quadrature/include/quadrature")

    def package_info(self):
        self.cpp_info.includedirs = ['.']
