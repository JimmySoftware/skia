bin\gn.exe gen out\win-x64-release --args="is_debug=false is_official_build=true target_cpu=\"x64\"" --ide=vs 
ninja -C out\win-x64-release 

dirsync "./out/win-x64-release"             "z:\__Finale\SkiaApps\out\win-x64-release" -v -c -p -s -o "^.*\.(a|so|lib)$"

