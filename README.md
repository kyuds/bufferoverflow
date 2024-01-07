# bufferoverflow
Exploiting buffer overflow

```
# build docker image
docker build -t bfo:poc .

# run docker container
docker run --name bfo -it bfo:poc /bin/sh

# run the buffer overflow sample
./exec.sh
```

The bufferoverflow problem is a really common and well-known exploit in computer security and more broadly computer science. However, for beginners starting with computer science, it is sort of hard to grasp exactly why the bufferoverflow problem is problematic. The standard explanation of "oh you can overwrite parts of memory that you shouldn't" is insufficient when faced with the question of: "how do you even know whats where? Isn't it impractical in practice?". 

This project attempts to give explanations on how stack-memory bufferoverflow problems maybe exploited in the C programming language (note that this is different from heap-memory bufferoverflow). More specifically, it shows how writing data into memory can be used to reroute the program to run code that is not called. If such operations are successful, then naturally attackers to any given system will have immediate full control over the specific process, and in the advent that the said process has elevated privileges, significant control over the machine. The project is run in a Dockerfile because performing a bufferoverflow exploit requires some security settings on the operating system to be turned off. Since we don't want to turn such settings off on our local machine, we use a container instead. 
