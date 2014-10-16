package main

import "fmt"

func ping(pings chan<- string, msg string) {
    pings <- msg
}

// the compile error reporter is fucking


// channel can be used as func parameters and can specify if the channel is meant to only send or
// receive values
func pong(pings <-chan string, pongs chan<-string) {
    msg := <-pings
    pongs <- msg
}

func main() {
    pings := make(chan string, 1)
    pongs := make(chan string, 1)

    //ping(pings, "passed messages")
    pings <- "passed message"
    pong(pings, pongs)
    fmt.Println(<-pongs)
}
