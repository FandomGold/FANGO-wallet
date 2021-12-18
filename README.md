![image](https://raw.githubusercontent.com/FandomGold/XFG-data/master/images/fangobgs.png)

# Fango Desktop (Private Bank & Messenger Wallet)
Latest Release: v4.0.0 (Dragonbourne)

<b><sub>Maintained by Fandom Gold Society</sub></b>

[![Build check](https://github.com/FandomGold/fango-desktop/actions/workflows/check.yml/badge.svg)](https://github.com/FandomGold/fango-desktop/actions/workflows/check.yml)
__________________________________________________
Fango Wallet is a decentralized blockchain banking interface & p2p private messenger powered by 100% open source code - without involvement of financial institutions. Enabling a secure & private way to store & transfer funds and private messages by using a distributed public ledger.

All Fango transactions and messages are private by default.

Fango Wallet is an extension of [Fango](https://github.com/fandomgold/fango) (XFG) - a secure peer-to-peer blockchain network based on the CryptoNote protocol and operates with no central authority. Allowing you the freedom (and responsibility) of full control over the private keys to your funds.

## Resources

-   Web: <https://fango.money>
-   GitHub: <https://github.com/fandomgold>
-   Discord: <https://discord.gg/5UJcJJg>
-   Twitter: <https://twitter.com/fandomgold>
-   Reddit: <https://www.reddit.com/r/Fango>
-   Medium: <https://medium.com/@fandomgold>
-   Bitcoin Talk: <https://bitcointalk.org/index.php?topic=2712001>

## Compiling Fango-Desktop from source

### Linux / Ubuntu

#### Prerequisites

Dependencies: GCC 4.7.3 or later, CMake 2.8.6 or later, Boost 1.55 or later, and Qt 5.9 or later.
You may download them from:

-   <https://gcc.gnu.org/>
-   <https://www.cmake.org/>
-   <https://www.boost.org/>
-   <https://www.qt.io>

On Ubuntu it is possible to install them using apt:

```bash
sudo apt install git gcc make cmake libboost-all-dev qt5-default
```

#### Building

To acquire the source via git and build the release version, run the following commands:

```bash
git clone https://github.com/FandomGold/fango-desktop
cd fango-desktop
rm -rf cryptonote
git clone https://github.com/FandomGold/fango cryptonote
make 
```

If the build is successful the binary will be in the `build/release` folder.

### Windows 10

#### Prerequisites

-   Install [Visual Studio 2017 Community Edition](https://www.visualstudio.com/thank-you-downloading-visual-studio/?sku=Community&rel=15&page=inlineinstall)
-   When installing Visual Studio, you need to install **Desktop development with C++** and the **VC++ v140 toolchain** components. The option to install the v140 toolchain can be found by expanding the "Desktop development with C++" node on the right. You will need this for the project to build correctly.
-   Install [CMake](https://cmake.org/download/)
-   Install [Boost 1.67.0](https://boost.teeks99.com/bin/1.67.0/), ensuring you download the installer for MSVC 14.1.
-   Install [Qt 5.11.0](https://www.qt.io/download)

#### Building

-   From the start menu, open 'x64 Native Tools Command Prompt for vs2017' or run "C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\Common7\\Tools\\VsMSBuildCmd.bat" from any command prompt.
-   Edit the CMakeLists.txt file and set the path to QT cmake folder. For example: set(CMAKE_PREFIX_PATH "C:\\Qt\\5.11.0\\msvc2017_64\\lib\\cmake\\").
-   `git clone https://github.com/FandomGold/fango`
-   `git clone https://github.com/FandomGold/fango-desktop`
-   Copy the contents of fango folder into fango-wallet\\cryptonote
-   `cd fango-desktop`
-   `mkdir build`
-   `cd build`
-   `cmake -G "Visual Studio 15 2017 Win64" -DBOOST_LIBRARYDIR:PATH=c:/local/boost_1_67_0 ..` (Or your boost installed dir.)
-   `msbuild FANGO-GUI.sln /p:Configuration=Release`

If the build is successful the binaries will be in the `Release` folder.

### macOS

#### Prerequisites

First, we need to install the same dependencies as [fango](https://github.com/FandomGold/fango#macos).

Once fango dependencies are installed, we need to install Qt5, open a Terminal and run the following commands:

```bash
brew install qt5
export PATH="/usr/local/opt/qt/bin:$PATH"
```

#### Building

When all dependencies are installed, build Fango Desktop with the following commands: 

```bash
git clone https://github.com/FandomGold/fango-desktop
cd fango-desktop
rm -rf cryptonote
git clone https://github.com/FandomGold/fango cryptonote
make build-release
```

If the build is successful the binary will be `build/release/FANGO-GUI.app`

It is also possible to deploy the application as a `.dmg` by using these commands after the build:

```bash
cd build/release
macdeployqt FANGO-GUI.app
cpack
```

## Special Thanks

Special thanks to developers from Cryptonote, Bytecoin, Conceal, Karbo, Monero, Forknote, XDN, TurtleCoin, and Masari.
