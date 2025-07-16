/**
 * @param {any} val
 * @return {Object}
 */
var expect = function(val) {
    return {
        toBe: function(n) {
            if (n === val) return true;
            else throw new Error("Not Equal");
        },
        notToBe: function(n) {
            if (n !== val) return true;
            else throw new Error("Equal");
        }
    };
};
