var fullJustify = function(words, maxWidth) {
    let result = [];
    let i = 0;

    while (i < words.length) {
        let line = [];
        let lineLength = 0;

        // 1. Find words that can fit in this line
        while (
            i < words.length &&
            lineLength + words[i].length + line.length <= maxWidth
        ) {
            line.push(words[i]);
            lineLength += words[i].length;
            i++;
        }

        let spaces = maxWidth - lineLength;
        let gaps = line.length - 1;

        // 2. Last line OR line with only one word
        if (i === words.length || gaps === 0) {
            let text = line.join(" ");
            text += " ".repeat(maxWidth - text.length);

            result.push(text);
        } 
        // 3. Fully justify the line
        else {
            let spaceBetween = Math.floor(spaces / gaps);
            let extraSpaces = spaces % gaps;

            let text = "";

            for (let j = 0; j < line.length - 1; j++) {
                text += line[j];

                let currentSpaces = spaceBetween;

                // Left gaps get extra spaces
                if (j < extraSpaces) {
                    currentSpaces++;
                }

                text += " ".repeat(currentSpaces);
            }

            text += line[line.length - 1];

            result.push(text);
        }
    }

    return result;
};