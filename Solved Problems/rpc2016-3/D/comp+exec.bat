if exist main.cpp (
  g++ main.cpp -o main.exe
  if exist file.in (
   main.exe < file.in > file.out
  ) else (
     echo no existe file.in  
   )
) else (
  echo no existe main.cpp
)
PAUSE
start file.out