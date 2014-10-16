package main

import "strconv"
import "fmt"

func main() {
    f, _ := strconv.ParseInt("5", 0,  2)
    fmt.Println(f)
}
