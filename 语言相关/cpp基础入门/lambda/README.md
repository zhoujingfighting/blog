## Lambda syntax

lambda function syntax

```
[capture list](parameter) -> return type{
        // Function body
}
```

example
```
auto func = [](){
    std::cout << "hello" << std::endl;
}
```

## capture list
```
[capture list](parameter) -> return type{
        // Function body
}
```

if lambda function want to access the context out of function, use capture list instead