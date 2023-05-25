#include <stdio.h>
#include "prom/prom.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "microhttpd.h"
#include "prom/promhttp.h"

int main(int argc, const char **argv)
{
    enum {LABELS_SZ = 5};
    /* Init all of prometheus */
    prom_collector_registry_default_init();
    
    // Set the active registry for the HTTP handler
    promhttp_set_active_collector_registry(NULL);

    /* Make counter */
    const char *counter_labels[LABELS_SZ] = {"counter_label_one", "counter_label_two", "counter_label_three", "counter_label_four", "counter_label_five"};
    prom_counter_t *my_counter = prom_counter_new("my_counter", "counts things", LABELS_SZ, counter_labels);
    prom_metric_t *counter_metric = prom_collector_registry_must_register_metric(my_counter);

    // /* Make gauge */
    // const char *gauge_labels[LABELS_SZ] = {"gauge_label_one", "gauge_label_two", "gauge_label_three", "gauge_label_four", "gauge_label_five"};
    // prom_gauge_t *my_gauge = prom_gauge_new("my_gauge", "gauges things", LABELS_SZ, gauge_labels);
    // prom_metric_t *gauge_metric = prom_collector_registry_must_register_metric(my_gauge);

    // /* Make histogram */
    // const char *histogram_labels[LABELS_SZ] = {"histogram_label_one", "histogram_label_two", "histogram_label_three", "histogram_label_four", "histogram_label_five"};
    // prom_histogram_t *my_histogram = prom_histogram_new("my_histogram", "histograms things", prom_histogram_buckets_linear(5.0, 5.0, 2), LABELS_SZ, histogram_labels);
    // prom_metric_t * histogram_metric = prom_collector_registry_must_register_metric(my_histogram);





















    // init();
    // int r = 0;
    // const char *labels[] = {"one", "two", "three", "four", "five"};

    // for (int i = 1; i <= 100; i++)
    // {
    //     double hist_value;
    //     if (i % 2 == 0)
    //     {
    //         hist_value = 3.0;
    //     }
    //     else
    //     {
    //         hist_value = 7.0;
    //     }

    //     r = prom_histogram_observe(test_histogram, hist_value, NULL);
    //     if (r)
    //         exit(1);

    //     for (int x = 0; x < 5; x++)
    //     {
    //         r = foo(i, labels[x]);
    //         if (r)
    //             exit(r);
    //         r = bar(i + x, labels[x]);
    //         if (r)
    //             exit(r);
    //     }
    // }

    struct MHD_Daemon *daemon = promhttp_start_daemon(MHD_USE_SELECT_INTERNALLY, 8000, NULL, NULL);
    if (daemon == NULL)
    {
        return 1;
    }

    // prom_counter_t *my_counter = prom_collector_registry_must_register_metric(prom_counter_new("my_counter", "counts things", 0, NULL));


    while (1)
    {
        for (int i = 0; i < LABELS_SZ; ++i) {
            prom_counter_inc(counter_metric, &counter_labels);
        }
        printf("Update...\n");
        sleep(3);
    }

    prom_collector_registry_destroy(PROM_COLLECTOR_REGISTRY_DEFAULT);
    MHD_stop_daemon(daemon);

    return 0;
}