const IsUnique = function () {};

/*
 * Use associative array like a hash table.
 */
IsUnique.prototype.part1 = function (str) {
  if (typeof str !== 'string') {
    throw Error('str is not a string!');
  }

  if (str.length === 0) {
    return true;
  }

  const lookup = [];
  const cleanStr = str.replace(/\s/g, '');

  for (let i = 0; i < cleanStr.length; i += 1) {
    if (lookup[cleanStr[i]] !== undefined) {
      return false;
    }

    lookup[cleanStr[i]] = true;
  }

  return true;
};

/*
 * Brute force O(n^2) approach.
 * No additional storage.
 * Could use .replace() to remove whitespace,
 * but regex package will likely use additional storage
 * space internally.
 */
IsUnique.prototype.part2 = function (str) {
  if (typeof str !== 'string') {
    throw Error('str is not a string!');
  } else if (str.length === 0) {
    return true;
  }

  for (let i = 0; i < str.length; i += 1) {
    if (!this.isWhitespace(str[i])) {
      for (let j = 0; j < str.length; j += 1) {
        if (i !== j
          && str[i] === str[j]
          && !this.isWhitespace(str[j])) {
          return false;
        }
      }
    }
  }

  return true;
};

/*
 * Test individual characters, if they are
 * whitespace chars, return true.  Otherwise, return false.
 * This is a helper function used by part1() and part2().
 */
IsUnique.prototype.isWhitespace = function (ch) {
  if (typeof ch !== 'string') {
    throw Error('ch is not a string!');
  } else if (ch.length !== 1) {
    throw Error('ch is not a single character!');
  }

  return /\s/.test(ch);
};

module.exports = IsUnique;
