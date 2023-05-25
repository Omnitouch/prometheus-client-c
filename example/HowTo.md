Build the example code with `make`
Run the example code with `./main`

Need to set the following in the `prometheus.yml` file

```YAML
scrape_configs:
    static_configs:
      - targets: ["0.0.0.0:8000"] # <-- prometheus-client-c exports data to this address
```

We run prometheus by calling `./prometheus --config.file=prometheus.yml`
Check out the page at `localhost:9090`