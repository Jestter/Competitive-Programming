if exist Main.java (
  javac Main.java
  if exist file.in (
   java Main < file.in > file.out
  ) else (
     echo no existe file.in  
   )
) else (
  echo no existe Main.java
)
PAUSE
start file.out