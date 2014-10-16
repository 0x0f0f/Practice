package main

import "fmt"
import "time"

// with the help of the select and channel, we get the timeouts implementatio
func main() {
    c1 := make(chan string, 1)
    go func() {
        time.Sleep(time.Second * 3)
        c1 <- "result 1"
    }()

    select {
    case res := <-c1:
        fmt.Println(res)
    case <-time.After(time.Second * 7):
        fmt.Println("timeout 1")
    }

    c2 := make(chan string, 1)
    go func() {
        time.Sleep(time.Second * 3)
        c2 <- "result 2"
    }()

    select {
    case res := <-c2:
        fmt.Println(res)
    case <- time.After(time.Second * 3):
        fmt.Println("timeout 2")

    }

}
