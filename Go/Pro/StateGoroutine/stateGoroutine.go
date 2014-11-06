package main
// sharing memory by communicating and having each piece of data owned by exactly 1 goroutine
import (
    "fmt"
    "math/rand"
    "sync/atomic"
    "time"
)

type readOp struct {
    key int
    resp chan int
}

type writeOp struct {
    key int
    val int
    resp chan bool
}

func main() {
    var ops  int64 = 0

    reads := make(chan *readOp) // what is the difference of  *readOp and readOp type
    writes := make(chan  *writeOp)

    go func() {
        var state = make(map[int]int)
        for {
            select {
            case read := <- reads:
                read.resp <-state[read.key]
            case write := <-writes:
                state[write.key] = write.val
                write.resp <- true
            }
        }
    }()

    for r := 0; r < 100; r++ {
        go func() {
            for {
                read := &readOp{
                    key: rand.Intn(5),
                    resp: make(chan int)}
                reads <- read
                <-read.resp
                atomic.AddInt64(&ops, 1)
            }
        }()
    }

    for w := 0; w < 10; w++ {
        go func() {
            for {
                write := &writeOp{
                    key: rand.Intn(5),
                    val: rand.Intn(100),
                    resp: make(chan bool),
                }
                writes <- write
                <-write.resp
                atomic.AddInt64(&ops, 1)
            }
        }()
    }

    time.Sleep(time.Second)
    opsFinal := atomic.LoadInt64(&ops)
    fmt.Println("ops:", opsFinal)
}
// sometimes, goroutine based approach was a bit more involved than the mutex-based one. 
// ** channel communication ** 
