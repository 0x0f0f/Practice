package main

import "fmt"

func main() {
    messages := make(chan string, 7) // if the size of chann is not designate, then the programm will fall into deadlock
    // how to make full use of the buffered chann?
    messages <- "buffered"
    messages <- "channel"

    fmt.Println(<-messages)
    fmt.Println(<-messages)
}
