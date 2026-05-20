This is just a personal project to help teach myself how to use rexglue sdk and not meant to be a huge project. I used claude ai to help guide myself so until I can learn to do this without assistance I don't see this being a real project.
If you're a wrestling fan and wanna fork this to make your own by all means do so as I would love to see someone smarter than me do this. So far it's Bootable and Playable, but loading saves does not work.

How to use:
Source your own WWE SmackDown Vs RAW 2007 (Xbox 360) files and place them all in the assets folder then run wwesmackdownvsraw2007


Linux Build Commands

cmake --preset linux-amd64-relwithdebinfo \
  -DCMAKE_C_COMPILER=clang-19 \
  -DCMAKE_CXX_COMPILER=clang++-19 \
  -DCMAKE_C_FLAGS="-msse4.1 -mssse3 -msse4.2" \
  -DCMAKE_CXX_FLAGS="-msse4.1 -mssse3 -msse4.2" \
  -DREXSDK_DIR=(rexglue-sdk Location)
cmake --build --preset linux-amd64-relwithdebinfo

Windows Build Commands

cmake -S . -B build -G "Ninja" 
  -DCMAKE_CXX_COMPILER=clang-cl 
  -DCMAKE_C_COMPILER=clang-cl 
  -DCMAKE_CXX_FLAGS="-target x86_64-pc-windows-msvc /EHsc -w -mssse3 /Zc:char8_t-" 
  -DCMAKE_C_FLAGS="-target x86_64-pc-windows-msvc -w -mssse3 /Zc:char8_t-" 
  -DCMAKE_BUILD_TYPE=Release 
  -DREXSDK_DIR=(rexglue-sdk Location)
cmake --build build --config Release

