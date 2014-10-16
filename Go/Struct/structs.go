package main

import "fmt"

type person struct {
    name string
    age int
}

func main() {
    fmt.Println(person{"bob", 20})

    fmt.Println(person{name:"Alice", age:30})

    fmt.Println(person{name:"fred"})

   fmt.Println(&person{name:"Ann", age:39})

    s := person {name:"sean", age:30}
    sp := &s
    fmt.Println(sp.age, sp.name)

    sp.age = 51
    fmt.Println(sp.age)
}
