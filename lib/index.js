// PQ
class PriorityQueue{
    heap = [];
    comparator = undefined;
    
    // NOTE: default minHeap, if you want to use maxHeap use (a,b) => b-a to comparator
    constructor(comparator = (a,b) => a-b){
        this.heap = [];
        this.comparator = comparator;
    }

    poll() {
        if(this.isEmpty()){
            return null;
        }
        let peak = this.heap[0];
        let last = this.heap.pop();
        if(this.size() != 0){
            this.heap[0] = last;
            this.downHeap(0);
        }
        return peak;
    }

    downHeap(pos) {
        while(this.isInternal(pos)){
            let s = null;

            if(!this.hasRight(pos)){
                s = this.left(pos);
            }else if(this.comparator(this.heap[this.left(pos)], this.heap[this.right(pos)])<= 0){
                s = this.left(pos);
            }else{
                s = this.right(pos);
            }
            if(this.comparator(this.heap[s], this.heap[pos]) < 0){
                this.swap(pos, s);
                pos = s;
            }else{
                break;
            }
        }
    }

    upHeap(pos) {
        while(!this.isRoot(pos)){
            let p = this.parent(pos);
            if(this.comparator(this.heap[p], this.heap[pos])<= 0){
                break;
            }
            this.swap(p, pos);
            pos = p;
        }
    }

    swap(a, b) {
        let tmp = this.heap[a];
        this.heap[a] = this.heap[b];
        this.heap[b] = tmp;
    }

    parent(pos) {return parseInt((pos - 1)/2)}

    left(pos) {return 2*pos + 1}

    right(pos) {return 2*pos + 2}

    size() {return this.heap.length}

    isInternal(pos) {return this.hasLeft(pos)}
    isRoot(pos) {return pos === 0}
    hasLeft(pos) {return this.left(pos) < this.size()}
    hasRight(pos) {return this.right(pos) < this.size()}
    isEmpty() {return this.heap.length == 0}
    insert(value) {
        this.heap.push(value);
        this.upHeap(this.size() - 1);
    }
    peak() {return this.heap[0]}
}

const minPq = new PriorityQueue((a,b) => a-b);
const maxPq = new PriorityQueue((a,b) => b-a);

minPq.insert(3);
minPq.insert(2);
minPq.insert(1);

console.log("min - ", minPq.poll(), minPq.poll(), minPq.poll());

maxPq.insert(3);
maxPq.insert(2);
maxPq.insert(1);

console.log("max - ",maxPq.poll(), maxPq.poll() ,maxPq.poll());
