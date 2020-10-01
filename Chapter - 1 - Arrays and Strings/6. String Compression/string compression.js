const stringCompressionModule = {
    compressString(str) {
      if (str === null) {
        throw new Error('input string str is null.');
      }
  
      if (typeof str !== 'string') {
        throw new Error('input string str is not a string.');
      }
  
      if (str.length === 0) {
        return str;
      }
  
      let currentChar = str[0];
      let count = 1;
      let output = '';
  
      for (let index = 1; index < str.length; index += 1) {
        if (str[index] !== currentChar) {
          output += currentChar + count;
          currentChar = str[index];
          count = 1;
        } else {
          count += 1;
        }
      }
  
      output += currentChar + count;
  
      if (str.length <= output.length) {
        return str;
      }
  
      return output;
    },
  };
  
  module.exports = stringCompressionModule;
  