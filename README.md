# bufferoverflow
Exploiting buffer overflow (stack-based)

```
# build docker image
docker build -t bfo:1 .

# run docker container
docker run -it bfo:1 /bin/sh

# run the buffer overflow sample
./bfo
```

### So how does buffer overflow work?
The buffer overflow vulnerability in essence is very simple: you overwrite parts of memory in the stack that you should not. The linux call stack is designed such that the stack grows downwards. Our point of concern is the return address when the function exists. Below the return address are our function parameters, and any other variable that we declare on the stack. By overwriting all contents of the stack including the return address, we can effectively change the return address and redirect program execution flow. In our case, we have a 8 byte pointer (parameter) and a one byte long character array on the stack below our return address (that is 8 bytes), so we have to force overwrite a total of 17 bytes when we buffer overflow using `strcpy` on the character array.
