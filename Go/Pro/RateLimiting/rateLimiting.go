package main

import "time"
import "fmt"

// go support the rate limiting with goroutines,channels and tickers
func main() {

    requests := make(chan int, 5)
    for i := 1; i <= 5; i++ {
        requests <- i
    }
    close(requests)

    limiter := time.Tick(time.Millisecond * 200)

    for req := range requests {
        <- limiter
        fmt.Println("requests: ", req, time.Now())
    }

    burstyLimiter := make(chan time.Time, 3)

    // make 3 burst req
    for i := 0; i < 3; i++ {
        burstyLimiter <- time.Now()
    }

    go func() {
        for t := range time.Tick(time.Millisecond * 200) {
            //fmt.Println(t)
            burstyLimiter <- t // add 2 req but the ticker is 200ms
        }
    }() // don't forget this a annoumous func

    burstyRequest := make(chan int, 5)
    for i := 1; i <= 5; i++ {
        burstyRequest <- i  // we have 5 requests
    }
    close(burstyRequest)

    for req := range burstyRequest {
        <- burstyLimiter // 3 instant req timers, and the left two are 200ms/req
        fmt.Println("requests ", req, time.Now())
    }
}
