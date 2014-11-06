package main

import "fmt"
import "time"

func worker(done chan bool) {
    fmt.Print("working....")
    time.Sleep(time.Second * 5)
    fmt.Println("done")

    done <- true // send the value to notify the done status
}

func main() {
     done := make(chan bool, 1)
     go worker(done)
     <- done // Block until we receive a notification from the worker
}

