package main

import "fmt"

func main() {
    messages := make(chan string)
    signals := make(chan bool)
    
    select {
    case msg:= <-messages:
        fmt.Println("received messages: ", msg)
    default:
        fmt.Println("No messages received")
    }

    msg := "hi"

    select {
    case messages <- msg:
        fmt.Println("send messages ", msg)
    default:
        fmt.Println("No messages received")
    }

    select {
    case msg := <-messages:
        fmt.Println("received messages: ", msg)
    case sig := <-signals:
        fmt.Println("received signals: ", sig)
    default:
        fmt.Println("No activity")
    }
}
