#!/bin/sh
# Requires MacPorts to be installed!
sudo xcode-select --install
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
brew install alure
sudo port -N install openjdk8 gmake cmake pkgconfig grpc protobuf-c glew glm libpng openal-soft libsndfile libogg libvorbis vorbis-tools box2D libdumb libsdl2 freetype libffi rapidjson libyaml libvpx pugixml yaml-cpp boost flac mpg123 libmodplug libopus opusfile
sudo git clone --recurse-submodules -j8 https://github.com/time-killer-games/stigma-dev /Applications/stigma-dev
cd /Applications/stigma-dev
sudo port -f activate libiconv
sudo gmake && sudo gmake emake
sudo chmod +x ./install.sh
sudo ./install.sh
sudo chmod +x ./start.sh
sudo port -f deactivate libiconv
echo "Installation Complete! You may now run the \"/Applications/stigma-dev/start.sh\" script from the terminal app!"