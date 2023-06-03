/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */
var chunk = function(arr, size) {
    let result=[];
    let e=[];
    for(let i of arr)
    {
        if(e.length==size)
        {
            result.push(e);
            e=[];
        }
        e.push(i);
    }
    if(e.length)
        result.push(e);
    return result;
};