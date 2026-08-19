var simplifyPath = function(path) {
    let stack = [];

    let parts = path.split('/');

    for (let part of parts) {

        // Ignore empty parts and "."
        if (part === "" || part === ".") {
            continue;
        }

        // Go to parent directory
        if (part === "..") {
            if (stack.length > 0) {
                stack.pop();
            }
        }

        // Valid directory/file name
        else {
            stack.push(part);
        }
    }

    return "/" + stack.join("/");
};