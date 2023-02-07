package seakmeng.seakmeng.models;

import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;

@Entity
public class Task {

    // auto generate the id
    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private Long id;

    private String task_date;
    private String task_name;
    private String task_description;
    private String task_status;

    public Task() {
    }

    //Constructor with fields
    public Task(String task_date, String task_name, String task_description, String task_status) {
        this.task_date = task_date;
        this.task_name = task_name;
        this.task_description = task_description;
        this.task_status = task_status;
    }

    public Long getId() {
        return this.id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getTask_date() {
        return this.task_date;
    }

    public void setTask_date(String task_date) {
        this.task_date = task_date;
    }

    public String getTask_name() {
        return this.task_name;
    }

    public void setTask_name(String task_name) {
        this.task_name = task_name;
    }

    public String getTask_description() {
        return this.task_description;
    }

    public void setTask_description(String task_description) {
        this.task_description = task_description;
    }

    public String getTask_status() {
        return this.task_status;
    }

    public void setTask_status(String task_status) {
        this.task_status = task_status;
    }
}
