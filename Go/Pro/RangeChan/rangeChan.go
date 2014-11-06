package main

import "fmt"

func main() {
    queue := make(chan string, 2)
    queue <- "one"
    queue <- "two"
    //queue <- "three"
    close(queue)

    // if you want range the channel, then you have to close it first
    for elem := range queue {
        fmt.Println(elem)
    }

}
