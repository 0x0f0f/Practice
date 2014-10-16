package main

import (
    "log"
    "runtime"
    "sync"
    "sync/atomic"
    "time"
)

const SizePerThread  = 1000000

type Queue struct {
    records string
    count int64
    incoming int64
    outing int64
}

func (q *Queue) push(record chan interface{}) {
    record <- time.Now()
    newcount := atomic.AddInt64(&q.count, 1)
    incoming := atomic.AddInt64(&q.incoming, 1)
    log.Printf("Push: %d, incoming %d\n", newcount, incoming)
}

func (q *Queue) pop(record chan interface{}) {
    <- record
    newcount := atomic.AddInt64(&q.count, -1)
    outing:= atomic.AddInt64(&q.outing, 1)
    log.Printf("Pop: %d, outing %d\n", newcount, outing)
}

func main() {
    var wg sync.WaitGroup
    runtime.GOMAXPROCS(runtime.NumCPU())
    record := make(chan interface{}, 100000)

    queue := new(Queue)
    wg.Add(20)

    for i := 0; i<10; i++ {
        go func() {
            defer wg.Done()
            for j := 0; j < SizePerThread; j++ {
                queue.push(record)
            }
        }()

        go func() {
            defer wg.Done()
            for j :=0; j < SizePerThread; j++ {
                queue.pop(record)
            }
        }()
    }

    wg.Wait()
}
