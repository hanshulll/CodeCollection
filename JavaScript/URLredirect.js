// This snippet can be used to do a redirect to a specified URL.

const redirect = (url, asLink = true) =>
    asLink ? (window.location.href = url) : window.location.replace(url);

redirect('https://google.com');