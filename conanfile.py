from conans import ConanFile, CMake


class LibGraphqlParserConan(ConanFile):
    name = "libgraphqlparser"
    version = "0.7.0"
    license = "MIT"
    url = "https://github.com/graphql/libgraphqlparser"
    description = "A GraphQL query parser in C++ with C and C++ APIs"
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake"

    def source(self):
        self.run("git clone https://github.com/graphql/libgraphqlparser.git")
        self.run("cd libgraphqlparser && git checkout v0.7.0")

    def build(self):
        cmake = CMake(self)
        cmake.configure(source_folder="libgraphqlparser")
        cmake.build()
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["libgraphqlparser"]
