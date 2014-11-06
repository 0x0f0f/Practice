package main

import "fmt"
import "time"

// use goroutine and channel to implement the WorkerPool
// produce the job
func worker(id int, jobs <-chan int, results chan<-int) {
    for j:= range jobs {
        fmt.Println("worker ", id, "processing job ", j)
        time.Sleep(time.Second * 20)
        results <- j * 2
    }
}

func main() {
    jobs := make(chan int, 100)
    results := make(chan int, 100)


// channel is blocked? then send msg to it. close the channel then for range the channel to get
// message 


    for j := 1; j<=9; j++ {
        jobs <- j
    }
    close(jobs)

    for w := 1; w <=3; w++ {
        go worker(w, jobs, results)
    }

    for a:= 1; a <= 9; a++ {
        <-results
    }

}
