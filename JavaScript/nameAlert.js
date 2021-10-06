<html>
  <head>
    <meta charset="UTF-8" />
    <script>
      function logSubmit(event) {
        log.textContent = `Form Submitted! Time stamp: ${event.timeStamp}`;
        event.preventDefault();
      }
      const form = document.getElementById('form');
      const log = document.getElementById('log');
      form.addEventListener('submit', logSubmit);
    </script>
  </head>
  <body>
    <form id="form">
      <label>Name: <input type="text" /></label>
      <br /><br />
      <button type="submit">Submit Form</button>
    </form>
    <p id="log"></p>
  </body>
</html>
