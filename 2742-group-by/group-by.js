/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
    const res = {};

    for(const obj of this){
        const key = fn(obj);
        if(!res.hasOwnProperty(key)){
            res[key] = [];
        }
        res[key].push(obj);
    }

    return res;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */