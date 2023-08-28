from conans import ConanFile, tools
from conans.tools import check_min_cppstd
from conans.errors import ConanInvalidConfiguration, ConanException
import os
from conans.tools import Version


#TODO find out how to source code and conan in one project
class modern_durak_game_shared(ConanFile):
    version ="1.0.0"
    name = "modern_durak_game_shared"
    homepage = "https://github.com/werto87/modern_durak_game_shared"
    description = "uses boost::fusion to help with serialization; json <-> user defined type"
    topics = ("json parse", "serialization", "user defined type")
    license = "BSL-1.0"
    url = "https://github.com/conan-io/conan-center-index"
    settings = "compiler"
    exports_sources = "modern_durak_game_shared/*"

    @property
    def _source_subfolder(self):
        return "source_subfolder"

    @property
    def _minimum_cpp_standard(self):
        return 17

    @property
    def _minimum_compilers_version(self):
        return {
            "Visual Studio": "15",
            "gcc": "7",
            "clang": "3.9",
            "apple": "10.0",
        }

    def configure(self):
        if self.settings.compiler.get_safe("cppstd"):
            tools.check_min_cppstd(self, self._minimum_cpp_standard)
        min_version = self._minimum_compilers_version.get(
            str(self.settings.compiler))
        if not min_version:
            self.output.warn("{} recipe lacks information about the {} "
                             "compiler support.".format(
                                 self.name, self.settings.compiler))
        else:
            if tools.Version(self.settings.compiler.version) < min_version:
                raise ConanInvalidConfiguration(
                    "{} requires C++{} support. "
                    "The current compiler {} {} does not support it.".format(
                        self.name, self._minimum_cpp_standard,
                        self.settings.compiler,
                        self.settings.compiler.version))

    def requirements(self):
        self.requires("durak/0.0.11@werto87/stable")

    def package(self):
        self.copy("modern_durak_game_shared/modern_durak_game_shared.hxx", dst="include/modern_durak_game_shared")

    def package_id(self):
        self.info.header_only()
