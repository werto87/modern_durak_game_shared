from conan import ConanFile


class Project(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"

    def configure(self):
        self.options["catch2"].with_main = True
        self.options["catch2"].with_benchmark = True

    def requirements(self):
        self.requires("modern_durak_game_option/latest")
        self.requires("catch2/2.13.9")
        self.requires("durak/1.0.3")
        self.requires("confu_json/1.0.1")