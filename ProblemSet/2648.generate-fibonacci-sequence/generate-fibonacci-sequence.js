/**
 * @return {Generator<number>}
 */
var fibGenerator = function*() {
    var i=0
    var j=1;
    yield i;
    yield j;
    while(true)
    {
        r=i+j;
        yield r;
        i=j;
        j=r;
    }
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */