<div align="center">

# EVC Guidelines

</div>

## Table of Contents
- [Downloading and Build](#downloading-and-build)
- [Manual](#manual)

<a name="downloading-and-build"></a>

## Installation and Build

### Downloading

To get the EVC, run the following command in your terminal:

```bash
git clone https://github.com/IHateGameDev/EVC.git
cd EVC

# Get APIMacros dependencies if they are not installed:
wget https://raw.github.com/IHateGameDev/APIMacros/getAPIMacros.sh | sh api # override shared useful
```

### Building

```bash
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Releas -DLAUNCH_TESTS=ON .. -G Ninja
ninja

ninja install
```

<a name="manual"></a>

## Manual
