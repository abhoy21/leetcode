/**
 * @param {...(null|boolean|number|string|Array|Object)} args
 * @return {number}
 */
// var argumentsLength = function(...args) {
//     return args.length;
// };

var argumentsLength = function(...args) {
    let cnt = 0;
    while(args[cnt] !== undefined){
        cnt++;
    }
    return cnt;
};

/**
 * argumentsLength(1, 2, 3); // 3
 */