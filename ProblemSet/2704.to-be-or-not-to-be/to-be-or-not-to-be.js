/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
    this.val=val;
    return {
        toBe: (i)=>{
            if(i===val)
                return true;
            else
                throw "Not Equal";
        },
        notToBe: (i)=>{
            if(i!==val)
                return true;
            else
                throw "Equal";
        }
    }
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */