package main

import "fmt"

func main() {
    s := make([]string, 3)
    fmt.Println("emp:", s)

    s[0] = "1"
    s[1] = "2"
    s[2] = "3"
    fmt.Println("s:", s)
    fmt.Println("len:", len(s))

    s = append(s, "4")
    s = append(s, "5")
    fmt.Println("S: ", s)
    fmt.Println("S len: ", len(s))
}
