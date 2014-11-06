package  main

import "fmt"

func main() {
    messages := make(chan string)

    go func() {
        messages  <- "ping1"
        messages  <- "ping2"
        messages  <- "ping3"
    }()
    // what is the channle's structure?  is it made up of messages

    msg := <- messages
    fmt.Println(msg)
    msg = <- messages
    fmt.Println(msg)
    msg = <- messages
    fmt.Println(msg)

    ch := make(chan int,3)
    go func() {
        ch <- 1
        ch <- 1
        ch <- 1
        ch <- 1
        ch <- 1
        ch <- 1
        ch <- 1
        h <- 1
    }()

    <- ch
    <- ch
    <- ch
}
