from conan import ConanFile
from conan.tools.cmake import CMakeToolchain

class Project(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators =  "CMakeDeps"

    def generate(self):
        tc = CMakeToolchain(self)
        tc.user_presets_path = False #workaround because this leads to useless options in cmake-tools configure
        tc.generate()


    def configure(self):
        self.options["catch2"].with_main = True
        self.options["catch2"].with_benchmark = True

    def requirements(self):
        self.requires("modern_durak_game_option/latest")
        self.requires("catch2/2.13.9")
        self.requires("durak/1.0.3")
        self.requires("confu_json/[>=1.0.2 <2]")        