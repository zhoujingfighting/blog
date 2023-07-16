import { Observable, of } from "rxjs";

// observable是一个

const sumObserver = {
    sum : 0,
    next(value) {
        console.log('Adding: ' + value);
        this.sum += value;
    },
    error() {
        // We actually could just remove this method
        // since we do not really care about errors right now

    },
    complete(){
        console.log('Sum equals: ' + this.sum);
    }
}

of(1,2,3) // Symchronously emits 1,2,3 and then complete
    .subscribe(sumObserver);