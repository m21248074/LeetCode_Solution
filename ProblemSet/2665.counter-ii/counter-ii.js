/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    return {
        cur: init,
        increment: function(){
            this.cur++;
            return this.cur;
        },
        decrement: function(){
            this.cur--;
            return this.cur;
        },
        reset: function(){
            this.cur=init;
            return this.cur;
        }
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */