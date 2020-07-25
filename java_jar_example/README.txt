# 多文件打包成jar包示例：

```
javac -d . MyJarCtn.java MyJarDriver.java
jar cfm MyJarTest.jar Manifest.txt MyJarTest/*
java -jar MyJarTest.jar
```

