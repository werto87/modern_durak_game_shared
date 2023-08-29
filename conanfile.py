from conans import ConanFile, tools
from conans.tools import check_min_cppstd
from conans.errors import ConanInvalidConfiguration, ConanException
import os
from conans.tools import Version


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

    def requirements(self):
        self.requires("durak/0.0.11@werto87/stable")
        self.requires("confu_json/1.0.0")

    def package(self):
        self.copy("modern_durak_game_shared/modern_durak_game_shared.hxx", dst="include/")

    def package_id(self):
        self.info.header_only()
