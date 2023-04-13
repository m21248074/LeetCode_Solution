/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    if(!functions.length) return x=>x;
    let first=functions.pop(0);
    return x=>compose(functions)(first(x));
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */