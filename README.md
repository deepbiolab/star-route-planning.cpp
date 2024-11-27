# A* Route Planning

A C++ project for route planning utilizing the A* search algorithm with OpenStreetMap data.

<img src="map.png" width="600" height="450" />

## Cloning

When cloning this project, be sure to use the `--recurse-submodules` flag. Using HTTPS:
```
git clone https://github.com/deepbiolab/star-route-planning.cpp.git --recurse-submodules
```
or with SSH:
```
git clone git@github.com:deepbiolab/star-route-planning.cpp.git --recurse-submodules
```



## **Prerequisites**

> This program has been tested on WSL Ubuntu 24.04 in 2024.11

Create a new [WSL Ubuntu](https://learn.microsoft.com/en-us/windows/wsl/install) Instance (If not exist)

```cmd
# in Windows PowerShell
wsl --install Ubuntu-24.04
```

After install WSL Ubuntu, install below basic packages in it

```bash
sudo apt update
sudo apt install -y build-essential
sudo apt install -y cmake
sudo apt install -y git
sudo apt install -y gcc g++
sudo apt install -y pkg-config
```
> make sure versions:
>
> -  `cmake` version `> 3.14`
> - `g++` version `> 7`



## Dependencies

#### Packages

```bash
sudo apt install -y libcairo2-dev
sudo apt install -y libgraphicsmagick1-dev
sudo apt install -y libpng-dev
```



#### Compile io2d

Then compile and install io2d:
```
cd ~
git clone --recurse-submodules https://github.com/cpp-io2d/P0267_RefImpl

# Update original svgpp to latest
cd P0267_RefImpl/P0267_RefImpl/Samples/svg/external
rm -rf svgpp
git clone --recurse-submodules https://github.com/svgpp/svgpp.git

# Update catch.hpp file
cd ~/P0267_RefImpl/P0267_RefImpl/Tests/Catch2/single_include/
rm catch.hpp
wget https://raw.githubusercontent.com/potassco/libpotassco/2003fc8a4fd0e9b1435108b05a8ac36706b14bd3/tests/catch.hpp

# Compile io2d
cd ~/P0267_RefImpl
mkdir Debug && cd Debug
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build .
make
sudo make install
```
## Compile
At that point the project code should be compliable and run:
```
# Compile project
cd ~/projects/
git clone https://github.com/deepbiolab/star-route-planning.cpp.git --recurse-submodules
cd star-route-planning.cpp
mkdir build && cd build
cmake -DTESTING="AStarSearch" ..
make
```



## Run project

```
cd star-route-planning.cpp/bin
./star-route-planning.cpp -f ../map.osm 
```

Or to specify a map file:
```
./star-route-planning.cpp -f ../<your_osm_file.osm>
```


## Testing

The testing executable is also placed in the `bin` directory. From within `bin`, you can run the unit tests as follows:

```bash
# Run unit tests
cd star-route-planning.cpp/bin/
./test
```

After run unit tests, printed results should like this:

```bash
[==========] Running 7 tests from 2 test cases.
[----------] Global test environment set-up.
[----------] 6 tests from RouteModelTest
[ RUN      ] RouteModelTest.RouteModelData
[       OK ] RouteModelTest.RouteModelData (63 ms)
[ RUN      ] RouteModelTest.RouteModelNode
[       OK ] RouteModelTest.RouteModelNode (55 ms)
[ RUN      ] RouteModelTest.NodeDistance
[       OK ] RouteModelTest.NodeDistance (52 ms)
[ RUN      ] RouteModelTest.NodeToRoad
[       OK ] RouteModelTest.NodeToRoad (52 ms)
[ RUN      ] RouteModelTest.FindNeighbors
[       OK ] RouteModelTest.FindNeighbors (51 ms)
[ RUN      ] RouteModelTest.FindClosestNode
[       OK ] RouteModelTest.FindClosestNode (53 ms)
[----------] 6 tests from RouteModelTest (326 ms total)

[----------] 1 test from RoutePlannerTest
[ RUN      ] RoutePlannerTest.AStarSearch
[       OK ] RoutePlannerTest.AStarSearch (59 ms)
[----------] 1 test from RoutePlannerTest (59 ms total)

[----------] Global test environment tear-down
[==========] 7 tests from 2 test cases ran. (386 ms total)
[  PASSED  ] 7 tests.
```



