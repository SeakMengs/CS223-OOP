package seakmeng.seakmeng.repositories;

import seakmeng.seakmeng.models.*;
import org.springframework.data.repository.CrudRepository;

public interface TaskRepository extends CrudRepository<Task, Long> {
}
